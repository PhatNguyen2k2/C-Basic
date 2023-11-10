const check = document.getElementById("check1");
$(document).ready(function () {
  $.ajaxSetup({ cache: false });
  setInterval(function () {
    check.addEventListener("click", () => {
      if (check.checked) {
        console.log("on");
      } else {
        console.log("off");
      }
    });
  }, 1000);
});
