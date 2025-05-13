 // var CheckC = "click"
    // document.getElementById("Nach_vorne").addEventListener(CheckC, () =>{
        
    //     if(CheckC == "click"){
    //         var listItem = document.getElementsByClassName("thermo-segment segment10")
    //         for(var i = 0; i < listItem.length; i++){
    //         listItem[i].classList.add('segment1010')
    //         }
    //         CheckC ='';
    //     }
        
    //     if(CheckC =='')
    //     {
    //         setTimeout( () =>{
    //         var listItem = document.getElementsByClassName("thermo-segment segment10")
    //         for(var i = 0; i < listItem.length; i++){
    //         listItem[i].classList.add('SRemow')
    //         CheckC = "click"
    //         }
            
    //         }, 3000)
    //     }
        
    // })




    
//     let isClicked = false;
// document.getElementById("Nach_vorne").addEventListener("click", () => {
//     const segments = document.querySelectorAll(".thermo-segment.segment10");
//     if (!isClicked) {
//         segments.forEach(segment => {
//             segment.classList.add('segment10');
//         });
//         isClicked = true;
//         setTimeout(() => {
//             segments.forEach(segment => {
//                 segment.classList.remove('segment10');
//                 segment.classList.add('SRemow');
//             });
//             // Optional: reset the state
//             isClicked = false;
//         }, 3000);
//     }
// });





//     var timeoutId; // To store the timeout reference
// var button = document.querySelector('#Nach_vorne');
// var targetSegment = document.querySelector(".thermo-segment.segment10");
// button.addEventListener('click', () => {
//     if (!targetSegment) return;
//     // Add the glow effect
//     targetSegment.classList.add('segment1010');
//     // Clear any existing timeout
//     clearTimeout(timeoutId);
//     // Set new timeout to remove the glow
//     timeoutId = setTimeout(() => {
//         targetSegment.classList.remove('segment1010');
//     }, 3000);
// });




// let timeoutId;
//     const button = document.querySelector('#Nach_vorne');
//     const targetSegments = document.querySelectorAll('.segment10');
//     button.addEventListener('click', () => {
//         // Add the glow class to all matching segments
//         targetSegments.forEach(segment => segment.classList.add('segment1010'));
//         // Reset the timeout if already running
//         clearTimeout(timeoutId);
//         // After 3 seconds, remove the glow
//         timeoutId = setTimeout(() => {
//             targetSegments.forEach(segment => segment.classList.remove('segment1010'));
//         }, 5000);
//     });




// const segmentsOrder = [
//         'segment10',
//         'segment9',
//         'segment8',
//         'segment7',
//         'segment6',
//         'segment5',
//         'segment4',
//         'segment3',
//         'segment2',
//         'segment1'
//     ];
//     let currentLevel = 0;
//     document.getElementById('Nach_vorne').addEventListener('click', () => {
//         if (currentLevel >= segmentsOrder.length) return;
//         const className = segmentsOrder[currentLevel];
//         const segments = document.querySelectorAll(`.thermo-segment.${className}`);
//         // Add highlight class
//         segments.forEach(seg => seg.classList.add('segment1010'));
//         // Set timeout to remove after 3 seconds
//         setTimeout(() => {
//             segments.forEach(seg => seg.classList.remove('segment1010'));
//         }, 3000);
//         currentLevel++;
//     });




// const segmentsOrder = [
//     'segment10',
//     'segment9',
//     'segment8',
//     'segment7',
//     'segment6',
//     'segment5',
//     'segment4',
//     'segment3',
//     'segment2',
//     'segment1'
// ];
// const segmentsEffects = [
//     'segment1010',
//     'segment99',
//     'segment88',
//     'segment77',
//     'segment66',
//     'segment55',
//     'segment44',
//     'segment33',
//     'segment22',
//     'segment11'
// ];
// let currentLevel = 0;
// var checekCurrentLevel = false;
// document.getElementById('Nach_vorne').addEventListener('click', () => {
//     if (currentLevel >= segmentsOrder.length) return;
//     const className = segmentsOrder[currentLevel];
//     const segments = document.querySelectorAll(`.thermo-segment.${className}`);
//     const classEffect = segmentsEffects[currentLevel];
//     // Add the glow class on top of existing style
//     segments.forEach(seg => seg.classList.add(classEffect));
//     currentLevel++;
//     // Remove it after 3 seconds
//     if(currentLevel == 9) return checekCurrentLevel = true;
//     if(checekCurrentLevel == true)
//     {
//         for(var currentLevelStatus = 9; currentLevelStatus >= 0; currentLevelStatus--)
//         {
//             // checekCurrentLevel = true;
//             // if (checekCurrentLevel == true) {
//             setTimeout(() => {
//             segments.forEach(seg => seg.classList.remove(classEffect));
//             }, 3000);   
//             // }
//         }
//     }  
// });








// const segmentsOrder = [
//     'segment10', 'segment9', 'segment8', 'segment7', 'segment6',
//     'segment5', 'segment4', 'segment3', 'segment2', 'segment1'
// ];
// const segmentsEffects = [
//     'segment1010', 'segment99', 'segment88', 'segment77', 'segment66',
//     'segment55', 'segment44', 'segment33', 'segment22', 'segment11'
// ];
// let currentLevel = 0;
// document.getElementById('Nach_vorne').addEventListener('click', () => {
//     if (currentLevel >= segmentsOrder.length) return;
//     const className = segmentsOrder[currentLevel];
//     const effectClass = segmentsEffects[currentLevel];
//     const segments = document.querySelectorAll(`.thermo-segment.${className}`);
//     segments.forEach(seg => seg.classList.add(effectClass));
//     currentLevel++;
//     // When we reach the top, begin removing each one in reverse order
//     if (currentLevel === segmentsOrder.length) {
//         for (let i = segmentsOrder.length - 1; i >= 0; i--) {
//             const classToRemove = segmentsEffects[i];
//             const targetSegments = document.querySelectorAll(`.thermo-segment.${segmentsOrder[i]}`);
            
//             setTimeout(() => {
//                 targetSegments.forEach(seg => seg.classList.remove(classToRemove));
//             }, (segmentsOrder.length - i) * 1000); // stagger each by 1s
//         }
//         // Reset level for next use
//         currentLevel = 0;
//     }
// });



const controlButtons = document.querySelectorAll('#Nach_vorne, #Rückwärts, #Nach_links, #Nach_rechts');
const segmentsOrder = [
    'segment10', 'segment9', 'segment8', 'segment7', 'segment6',
    'segment5', 'segment4', 'segment3', 'segment2', 'segment1'
];
const segmentsEffects = [
    'segment1010', 'segment99', 'segment88', 'segment77', 'segment66',
    'segment55', 'segment44', 'segment33', 'segment22', 'segment11'
];
let currentLevel = 0;
controlButtons.forEach(button => {
    button.addEventListener('click', () => {
        if (currentLevel >= segmentsOrder.length) return;
        const className = segmentsOrder[currentLevel];
        const effectClass = segmentsEffects[currentLevel];
        const segments = document.querySelectorAll(`.thermo-segment.${className}`);
        segments.forEach(seg => seg.classList.add(effectClass));
        setTimeout(() => {
            segments.forEach(seg => seg.classList.remove(effectClass));
            // Auto-reset when last level is reached
            if (currentLevel === segmentsOrder.length - 1) {
                segmentsOrder.forEach((cls, i) => {
                    document.querySelectorAll(`.thermo-segment.${cls}`).forEach(el =>
                        el.classList.remove(segmentsEffects[i])
                    );
                });
                currentLevel = 0;
            } else {
                currentLevel++;
            }
        }, 3000);
    });
});



// const controlButtonIds = ["Nach_vorne", "Rückwärts", "Nach_links", "Nach_rechts"];
// const segmentsOrder = [
//     "segment10", "segment9", "segment8", "segment7", "segment6",
//     "segment5", "segment4", "segment3", "segment2", "segment1"
// ];
// const segmentsEffects = [
//     "segment1010", "segment99", "segment88", "segment77", "segment66",
//     "segment55", "segment44", "segment33", "segment22", "segment11"
// ];
// let currentLevel = 0;
// // Attach the same logic to all 4 buttons
// controlButtonIds.forEach(buttonId => {
//     const button = document.getElementById(buttonId);
//     button.addEventListener("click", () => {
//         if (currentLevel >= segmentsOrder.length) return;
//         const className = segmentsOrder[currentLevel];
//         const effectClass = segmentsEffects[currentLevel];
//         const segments = document.querySelectorAll(`.thermo-segment.${className}`);
//         segments.forEach(seg => seg.classList.add(effectClass));
//         // Remove after 3 seconds
//         setTimeout(() => {
//             segments.forEach(seg => seg.classList.remove(effectClass));
//         }, 3000);
//         currentLevel++;
//     });
// });




// button.addEventListener("click", () => {
//     if (currentLevel >= segmentsOrder.length) {
//         currentLevel = 0; // reset here
//     }
//     const className = segmentsOrder[currentLevel];
//     const effectClass = segmentsEffects[currentLevel];
//     const segments = document.querySelectorAll(`.thermo-segment.${className}`);
//     segments.forEach(seg => seg.classList.add(effectClass));
//     setTimeout(() => {
//         segments.forEach(seg => seg.classList.remove(effectClass));
//     }, 3000);
//     currentLevel++;
// });
// const segmentsOrder = [
//     'segment10', 'segment9', 'segment8', 'segment7', 'segment6',
//     'segment5', 'segment4', 'segment3', 'segment2', 'segment1'
// ];
// const segmentsEffects = [
//     'segment1010', 'segment99', 'segment88', 'segment77', 'segment66',
//     'segment55', 'segment44', 'segment33', 'segment22', 'segment11'
// ];
// let currentLevel = 0;
// const buttons = ['Nach_vorne', 'Rückwärts', 'Nach_links', 'Nach_rechts'];
// buttons.forEach(id => {
//     document.getElementById(id).addEventListener('click', () => {
//         if (currentLevel >= segmentsOrder.length) return;
//         const segClass = segmentsOrder[currentLevel];
//         const effectClass = segmentsEffects[currentLevel];
//         const elements = document.querySelectorAll(`.thermo-segment.${segClass}`);
//         elements.forEach(el => el.classList.add(effectClass));
//         setTimeout(() => {
//             elements.forEach(el => el.classList.remove(effectClass));
//             // Auto-reset if it was the last level
//             if (currentLevel === segmentsOrder.length - 1) {
//                 // Remove all applied styles from all segments
//                 segmentsOrder.forEach((cls, i) => {
//                     document.querySelectorAll(`.thermo-segment.${cls}`).forEach(el =>
//                         el.classList.remove(segmentsEffects[i])
//                     );
//                 });
//                 currentLevel = 0;
//             } else {
//                 currentLevel++;
//             }
//         }, 3000);
//     });
// });


//Your computer or phone making the request must be on the same Wi-Fi network as the ESP32.
// You cannot host the website online (without CORS issues) unless you configure CORS headers on ESP32 or use a proxy server.
// Use 192.168.x.x IP address from ESP32 serial monitor.


fetch("http://192.168.1.42/")
        .then(response => response.text())
        .then(data => console.log("ESP32 says:", data))
        .catch(err => console.error("Error connecting to ESP32:", err));
