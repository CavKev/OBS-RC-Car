document.getElementById("logo").addEventListener("click", function () {
    // Create overlay
    const overlay = document.createElement("div");
    overlay.style.position = "fixed";
    overlay.style.top = 0;
    overlay.style.left = 0;
    overlay.style.width = "100vw";
    overlay.style.height = "100vh";
    overlay.style.backgroundColor = "rgba(0, 0, 0, 0.5)";
    overlay.style.zIndex = 9999;

    // Create container for top alert
    const alertContainer = document.createElement("div");
    alertContainer.style.position = "absolute";
    alertContainer.style.top = "20px";
    alertContainer.style.left = "50%";
    alertContainer.style.transform = "translateX(-50%)";
    alertContainer.style.background = "black";
    alertContainer.style.padding = "20px";
    alertContainer.style.borderRadius = "15px";
    alertContainer.style.boxShadow = "0 0 20px white";
    alertContainer.style.display = "flex";
    alertContainer.style.flexDirection = "column";
    alertContainer.style.alignItems = "center";
    alertContainer.style.gap = "10px";
    const imagDiv = document.createElement("div")
    imagDiv.style.flexDirection = "column";
    // Create image1
    const img = document.createElement("img");
    img.src = "images/1719500998243.jpg"; // Replace with your desired image path
    img.style.width = "150px";
    img.style.height = "150px";
    img.style.borderRadius = "50%";
    img.style.border = "4px solid white";
    img.style.boxShadow = "0 0 15px yellow";
    // img.style.display = ""
    // Create image2
    const img2 = document.createElement("img");
    img2.src = "images/20200618_164608.jpg"; // Replace with your desired image path
    img2.style.width = "150px";
    img2.style.height = "150px";
    img2.style.borderRadius = "50%";
    img2.style.border = "4px solid white";
    img2.style.boxShadow = "0 0 15px yellow";
    // Create image3
    const img3 = document.createElement("img");
    img3.src = "images/IMG_20250527_125450.jpg"; // Replace with your desired image path
    img3.style.width = "150px";
    img3.style.height = "150px";
    img3.style.borderRadius = "50%";
    img3.style.border = "4px solid white";
    img3.style.boxShadow = "0 0 15px yellow";

    //Added developer's names
    const text = document.createElement("h3");
    text.innerText = 'This project was developed by developers'
    text.style.color = '#ffffff';
    // Optional: close button
    const closeBtn = document.createElement("button");
    closeBtn.textContent = "Close";
    closeBtn.style.marginTop = "10px";
    closeBtn.style.padding = "10px 20px";
    closeBtn.style.borderRadius = "10px";
    closeBtn.style.background = "red";
    closeBtn.style.color = "white";
    closeBtn.style.cursor = "pointer";
    closeBtn.style.border = "none";
    closeBtn.addEventListener("click", () => overlay.remove());

    // Assemble
    alertContainer.appendChild(text);
    alertContainer.appendChild(imagDiv);
    imagDiv.appendChild(img);
    imagDiv.appendChild(img2);
    imagDiv.appendChild(img3);
    alertContainer.appendChild(closeBtn);
    overlay.appendChild(alertContainer);
    document.body.appendChild(overlay);
});







const SpeedInKmControler2 = document.getElementById("SpeedInKm2");
const SpeedInKmControler = document.getElementById("SpeedInKm");
const controlButtons = document.querySelectorAll('#Nach_vorne, #Nach_links, #Nach_rechts');
const rückwärtsBtn = document.getElementById("Rückwärts");
const stopBtn = document.getElementById("stop_btn");

const Time = [0, 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160];
const Speed_IndicatorEffects = [
  'speed_indicator1-', 'speed_indicator2-', 'speed_indicator3-', 'speed_indicator4-', 'speed_indicator5-', 
  'speed_indicator6-', 'speed_indicator7-', 'speed_indicator8-', 'speed_indicator9-', 'speed_indicator10',
  'speed_indicator9', 'speed_indicator8', 'speed_indicator7', 'speed_indicator6', 'speed_indicator5', 
  'speed_indicator4', 'speed_indicator3', 'speed_indicator2', 'speed_indicator1'
];

let currentLevel = 0;
const segments = document.querySelectorAll('.speed_indicator');

function updateSpeedIndicator(level) {
  segments.forEach(seg => {
    Speed_IndicatorEffects.forEach(cls => seg.classList.remove(cls));
    seg.classList.remove("fire");
  });

  SpeedInKmControler2.classList.remove("fire");
  SpeedInKmControler.classList.remove("fire");
  
  const effectClass = Speed_IndicatorEffects[level];
  segments.forEach(seg => seg.classList.add(effectClass));

  // Update speed display
  SpeedInKmControler2.innerHTML = `${Time[level]} Km/h`;
  SpeedInKmControler.innerHTML = `${Time[level]} Km/h`;

  // Apply fire animation if at max level
  if (level === Speed_IndicatorEffects.length - 1 || Time[level] === 160) {
    segments.forEach(seg => seg.classList.add("fire"));
    SpeedInKmControler2.classList.add("fire");
    SpeedInKmControler.classList.add("fire");
  }
}

// Initial load
updateSpeedIndicator(currentLevel);

// Forward / Left / Right
controlButtons.forEach(button => {
  button.addEventListener('click', () => {
    if (currentLevel >= Speed_IndicatorEffects.length - 1 || currentLevel >= Time.length - 1) return;
    currentLevel++;
    updateSpeedIndicator(currentLevel);
  });
});

// Rückwärts
rückwärtsBtn.addEventListener('click', () => {
  if (currentLevel <= 0) return;
  currentLevel--;
  updateSpeedIndicator(currentLevel);
});

// Stop
stopBtn.addEventListener('click', () => {
  currentLevel = 0;
  updateSpeedIndicator(currentLevel);
});
