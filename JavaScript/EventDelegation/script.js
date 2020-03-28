document.getElementById("parent-list").addEventListener("click", function(e) {
    if (e.target && e.target.nodeName == "LI") {
        console.log("List item", e.target.id, "was clicked!");
        console.log(e);
    }
});

/*
Click events from child nodes get propagated to parent which 
catches them.
*/

// document.getElementById("myDIV").addEventListener("click", function(e) {
//     console.log("Yo baby! The DIV with id", e.target.id, "was clicked!");       
// });