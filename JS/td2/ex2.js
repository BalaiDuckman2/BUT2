let planete = "Lune, Terre, Mars";
let tabPlanete1=planete.split(",");
tabPlanete1.shift();
let tabPlanete2=["Ceres","Saturne","Pluton"];
let tabPlanete=tabPlanete1.concat(tabPlanete2);
tabPlanete.unshift("Mercure","Venus");
tabPlanete.pop();
tabPlanete.push("Uranus");
alert(tabPlanete.indexOf("Ceres"));

alert(tabPlanete);