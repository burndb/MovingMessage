#include <Arduino.h>

/* webpage with button template and input field */
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>MovingMessage</title>
  <meta name="viewport" content="width=device-width, initial-scale=0.7, maximum-scale=0.7">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center; overflow: hidden;}
    h2 {font-size: 3.0rem;}
    p {font-size: 3.0rem;}
    body {max-width: 600px; margin: auto; overflow: hidden; padding-bottom: 25px;}
    .switch {position: relative; display: inline-block; width: 120px; height: 68px} 
    .switch input {display: none}
    .slider {position: absolute; top: 0; left: 0; right: 0; bottom: 0; background-color: #218B96; border-radius: 6px}
    .slider:before {position: absolute; content: ""; height: 52px; width: 52px; left: 8px; bottom: 8px; background-color: #000; -webkit-transition: .4s; transition: .4s; border-radius: 3px}
    .slider2 {direction: rtl}
    input[type=range]::-webkit-slider-runnable-track  {-webkit-appearance: none; box-shadow: none; border: 2px solid black; border-radius: 5px; background: #38ECFF}
    input:checked+.slider {background-color: #38ECFF}
    input:checked+.slider:before {-webkit-transform: translateX(52px); -ms-transform: translateX(52px); transform: translateX(52px)}
  </style>
</head>
<body>
  <h1>Moving Message</h1>
  %BUTTONS%
  <div><h2>Speed Setting</h2></div>
  <input type="range" onchange="updateSpeed(this)" id="3" min="5" max="10" value="%SLIDERVALUE%" step="1" class="slider2">
  <div><h2>String Ausgabe</h2></div>
  <input type="text" id="2" maxlength="15" oninput="this.value = this.value.toUpperCase()" onkeyup="updateDisplay(this.value)" size="20">
 <br> 
<script>function togglePower(element) {
            var xhr = new XMLHttpRequest();
            if(element.checked){ xhr.open("GET", "/run?power=on", true); }
            else { xhr.open("GET", "/run?power=off", true); }
            xhr.send();
        }
        function toggleMode(element) {
            var xhr = new XMLHttpRequest();
            if(element.checked){ xhr.open("GET", "/mode?direction=left", true); }
            else { xhr.open("GET", "/mode?direction=right", true); }
            xhr.send();
        }
        function updateDisplay(str) {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "/update?string="+str, true);
            xhr.send();
        }
        function updateSpeed(element) {
            var sliderValue = document.getElementById("3").value;
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "/slider?speed="+sliderValue, true);
  xhr.send();
}
</script>
</body>
</html>
)rawliteral";