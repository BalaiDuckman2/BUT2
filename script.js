const chessboard = document.getElementById('chessboard');
let selectedPiece = null;
let currentPlayer = 'white';
let enPassantSquare = null;
let isComputerPlayer = true; // L'ordinateur joue les noirs

const initialBoard = [
    ['♜', '♞', '♝', '♛', '♚', '♝', '♞', '♜'],
    ['♟', '♟', '♟', '♟', '♟', '♟', '♟', '♟'],
    ['', '', '', '', '', '', '', ''],
    ['', '', '', '', '', '', '', ''],
    ['', '', '', '', '', '', '', ''],
    ['', '', '', '', '', '', '', ''],
    ['♙', '♙', '♙', '♙', '♙', '♙', '♙', '♙'],
    ['♖', '♘', '♗', '♕', '♔', '♗', '♘', '♖']
];

let board = JSON.parse(JSON.stringify(initialBoard));

const pieceTypes = {
    '♙': 'whitePawn',
    '♖': 'whiteRook',
    '♘': 'whiteKnight',
    '♗': 'whiteBishop',
    '♕': 'whiteQueen',
    '♔': 'whiteKing',
    '♟': 'blackPawn',
    '♜': 'blackRook',
    '♞': 'blackKnight',
    '♝': 'blackBishop',
    '♛': 'blackQueen',
    '♚': 'blackKing'
};

const pieceValues = {
    'Pawn': 1,
    'Knight': 3,
    'Bishop': 3,
    'Rook': 5,
    'Queen': 9,
    'King': 100
};

function createBoard() {
    chessboard.innerHTML = '';
    for (let i = 0; i < 8; i++) {
        for (let j = 0; j < 8; j++) {
            const square = document.createElement('div');
            square.classList.add('square');
            square.classList.add((i + j) % 2 === 0 ? 'white' : 'black');
            square.dataset.row = i;
            square.dataset.col = j;
            square.addEventListener('click', handleSquareClick);
            
            const piece = board[i][j];
            if (piece) {
                square.textContent = piece;
                square.classList.add('piece');
            }
            
            chessboard.appendChild(square);
        }
    }
}

function handleSquareClick(event) {
    if (currentPlayer === 'black' && isComputerPlayer) return;

    const clickedSquare = event.target;
    const row = parseInt(clickedSquare.dataset.row);
    const col = parseInt(clickedSquare.dataset.col);
    
    if (selectedPiece) {
        const selectedRow = parseInt(selectedPiece.dataset.row);
        const selectedCol = parseInt(selectedPiece.dataset.col);
        const pieceType = pieceTypes[board[selectedRow][selectedCol]];
        
        if (isValidMove(selectedRow, selectedCol, row, col, pieceType)) {
            movePiece(selectedRow, selectedCol, row, col);
            selectedPiece.classList.remove('selected');
            selectedPiece = null;
            currentPlayer = 'black';
            
            updateGameStatus();
            
            if (isComputerPlayer && !isGameOver()) {
                setTimeout(computerMove, 500);
            }
        }
    } else if (clickedSquare.classList.contains('piece')) {
        const pieceColor = pieceTypes[board[row][col]].startsWith('white') ? 'white' : 'black';
        if (pieceColor === currentPlayer) {
            selectedPiece = clickedSquare;
            selectedPiece.classList.add('selected');
        }
    }
}

function isValidMove(fromRow, fromCol, toRow, toCol, pieceType) {
    const dx = toCol - fromCol;
    const dy = toRow - fromRow;
    
    // Vérification de base : ne pas capturer ses propres pièces
    if (board[toRow][toCol] && pieceTypes[board[toRow][toCol]].startsWith(currentPlayer)) {
        return false;
    }
    
    switch (pieceType) {
        case 'whitePawn':
            if (fromRow === 6 && dy === -2 && dx === 0 && !board[fromRow-1][fromCol] && !board[toRow][toCol]) return true;
            if (dy === -1 && dx === 0 && !board[toRow][toCol]) return true;
            if (dy === -1 && Math.abs(dx) === 1 && (board[toRow][toCol] || (toRow === 2 && toCol === enPassantSquare))) return true;
            return false;
        case 'blackPawn':
            if (fromRow === 1 && dy === 2 && dx === 0 && !board[fromRow+1][fromCol] && !board[toRow][toCol]) return true;
            if (dy === 1 && dx === 0 && !board[toRow][toCol]) return true;
            if (dy === 1 && Math.abs(dx) === 1 && (board[toRow][toCol] || (toRow === 5 && toCol === enPassantSquare))) return true;
            return false;
        case 'whiteRook':
        case 'blackRook':
            return (dx === 0 || dy === 0) && isPathClear(fromRow, fromCol, toRow, toCol);
        case 'whiteKnight':
        case 'blackKnight':
            return (Math.abs(dx) === 2 && Math.abs(dy) === 1) || (Math.abs(dx) === 1 && Math.abs(dy) === 2);
        case 'whiteBishop':
        case 'blackBishop':
            return Math.abs(dx) === Math.abs(dy) && isPathClear(fromRow, fromCol, toRow, toCol);
        case 'whiteQueen':
        case 'blackQueen':
            return (dx === 0 || dy === 0 || Math.abs(dx) === Math.abs(dy)) && isPathClear(fromRow, fromCol, toRow, toCol);
        case 'whiteKing':
        case 'blackKing':
            if (Math.abs(dx) <= 1 && Math.abs(dy) <= 1) return true;
            // Roque
            if (dy === 0 && Math.abs(dx) === 2) {
                const rookCol = dx > 0 ? 7 : 0;
                const rookRow = currentPlayer === 'white' ? 7 : 0;
                if (canCastle(fromRow, fromCol, rookRow, rookCol)) return true;
            }
            return false;
    }
}

function isPathClear(fromRow, fromCol, toRow, toCol) {
    const dx = Math.sign(toCol - fromCol);
    const dy = Math.sign(toRow - fromRow);
    let x = fromCol + dx;
    let y = fromRow + dy;
    
    while (x !== toCol || y !== toRow) {
        if (board[y][x]) return false;
        x += dx;
        y += dy;
    }
    
    return true;
}

function movePiece(fromRow, fromCol, toRow, toCol) {
    const piece = board[fromRow][fromCol];
    const pieceType = pieceTypes[piece];
    
    // Prise en passant
    if ((pieceType === 'whitePawn' || pieceType === 'blackPawn') && toCol === enPassantSquare) {
        board[fromRow][toCol] = '';
        document.querySelector(`[data-row="${fromRow}"][data-col="${toCol}"]`).textContent = '';
    }
    
    // Mise à jour de la prise en passant
    enPassantSquare = null;
    if ((pieceType === 'whitePawn' && fromRow === 6 && toRow === 4) ||
        (pieceType === 'blackPawn' && fromRow === 1 && toRow === 3)) {
        enPassantSquare = toCol;
    }
    
    // Roque
    if (pieceType.endsWith('King') && Math.abs(toCol - fromCol) === 2) {
        const rookFromCol = toCol > fromCol ? 7 : 0;
        const rookToCol = toCol > fromCol ? toCol - 1 : toCol + 1;
        board[toRow][rookToCol] = board[toRow][rookFromCol];
        board[toRow][rookFromCol] = '';
        document.querySelector(`[data-row="${toRow}"][data-col="${rookToCol}"]`).textContent = board[toRow][rookToCol];
        document.querySelector(`[data-row="${toRow}"][data-col="${rookFromCol}"]`).textContent = '';
    }
    
    board[toRow][toCol] = piece;
    board[fromRow][fromCol] = '';
    createBoard();
}

function canCastle(kingRow, kingCol, rookRow, rookCol) {
    const kingPiece = board[kingRow][kingCol];
    const rookPiece = board[rookRow][rookCol];
    
    if (!kingPiece || !rookPiece) return false;
    if (kingPiece !== (currentPlayer === 'white' ? '♔' : '♚')) return false;
    if (rookPiece !== (currentPlayer === 'white' ? '♖' : '♜')) return false;
    
    const direction = rookCol > kingCol ? 1 : -1;
    for (let col = kingCol + direction; col !== rookCol; col += direction) {
        if (board[kingRow][col]) return false;
    }
    
    return !isCheck(currentPlayer);
}

function isCheck(player) {
    const kingSymbol = player === 'white' ? '♔' : '♚';
    let kingRow, kingCol;
    
    // Trouver le roi
    for (let i = 0; i < 8; i++) {
        for (let j = 0; j < 8; j++) {
            if (board[i][j] === kingSymbol) {
                kingRow = i;
                kingCol = j;
                break;
            }
        }
        if (kingRow !== undefined) break;
    }
    
    // Vérifier si une pièce adverse peut atteindre le roi
    for (let i = 0; i < 8; i++) {
        for (let j = 0; j < 8; j++) {
            if (board[i][j] && !pieceTypes[board[i][j]].startsWith(player)) {
                if (isValidMove(i, j, kingRow, kingCol, pieceTypes[board[i][j]])) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

function isCheckmate(player) {
    if (!isCheck(player)) return false;
    
    for (let i = 0; i < 8; i++) {
        for (let j = 0; j < 8; j++) {
            if (board[i][j] && pieceTypes[board[i][j]].startsWith(player)) {
                for (let x = 0; x < 8; x++) {
                    for (let y = 0; y < 8; y++) {
                        if (isValidMove(i, j, x, y, pieceTypes[board[i][j]])) {
                            const tempPiece = board[x][y];
                            board[x][y] = board[i][j];
                            board[i][j] = '';
                            const stillInCheck = isCheck(player);
                            board[i][j] = board[x][y];
                            board[x][y] = tempPiece;
                            if (!stillInCheck) return false;
                        }
                    }
                }
            }
        }
    }
    
    return true;
}

function computerMove() {
    const moves = getAllPossibleMoves('black');
    if (moves.length === 0) return;

    const move = selectBestMove(moves);
    movePiece(move.fromRow, move.fromCol, move.toRow, move.toCol);
    currentPlayer = 'white';
    updateGameStatus();
}

function getAllPossibleMoves(player) {
    const moves = [];
    for (let i = 0; i < 8; i++) {
        for (let j = 0; j < 8; j++) {
            if (board[i][j] && pieceTypes[board[i][j]].startsWith(player)) {
                for (let x = 0; x < 8; x++) {
                    for (let y = 0; y < 8; y++) {
                        if (isValidMove(i, j, x, y, pieceTypes[board[i][j]])) {
                            moves.push({fromRow: i, fromCol: j, toRow: x, toCol: y});
                        }
                    }
                }
            }
        }
    }
    return moves;
}

function selectBestMove(moves) {
    let bestMove = null;
    let bestScore = -Infinity;

    for (const move of moves) {
        const score = evaluateMove(move);
        if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }

    return bestMove;
}

function evaluateMove(move) {
    const capturedPiece = board[move.toRow][move.toCol];
    let score = 0;

    // Valeur de la pièce capturée
    if (capturedPiece) {
        const pieceType = pieceTypes[capturedPiece].replace('white', '').replace('black', '');
        score += pieceValues[pieceType];
    }

    // Bonus pour l'avancement des pions
    if (pieceTypes[board[move.fromRow][move.fromCol]].endsWith('Pawn')) {
        score += (7 - move.toRow) * 0.1;
    }

    // Bonus pour le contrôle du centre
    if ((move.toRow === 3 || move.toRow === 4) && (move.toCol === 3 || move.toCol === 4)) {
        score += 0.5;
    }

    return score;
}

function updateGameStatus() {
    const gameInfo = document.getElementById('gameInfo');
    if (isCheckmate(currentPlayer)) {
        gameInfo.textContent = `Échec et mat ! ${currentPlayer === 'white' ? 'Les noirs' : 'Les blancs'} gagnent !`;
    } else if (isCheck(currentPlayer)) {
        gameInfo.textContent = `${currentPlayer === 'white' ? 'Roi blanc' : 'Roi noir'} en échec !`;
    } else {
        gameInfo.textContent = `Tour des ${currentPlayer === 'white' ? 'Blancs' : 'Noirs'}`;
    }
}

function isGameOver() {
    return isCheckmate('white') || isCheckmate('black');
}

createBoard();
updateGameStatus();