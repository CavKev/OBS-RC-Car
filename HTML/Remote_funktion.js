const controlButtons = document.querySelectorAll('#Nach_vorne, #Nach_links, #Nach_rechts');
const rückwärtsBtn = document.getElementById("Rückwärts");
const stopBtn = document.getElementById("stop_btn");

const segmentsOrder = [
    'segment1-', 'segment2-', 'segment3-', 'segment4-', 'segment5-', 'segment6-', 'segment6-', 'segment7-', 'segment8-', 'segment9-',
    'segment10', 'segment9', 'segment8', 'segment7', 'segment6',
    'segment5', 'segment4', 'segment3', 'segment2', 'segment1'
];
const segmentsEffects = [
    'segment11-', 'segment22-', 'segment33-', 'segment44-', 'segment55-', 'segment66-', 'segment77-', 'segment88-', 'segment99-',
    'segment1010', 'segment99', 'segment88', 'segment77', 'segment66',
    'segment55', 'segment44', 'segment33', 'segment22', 'segment11'
];

let currentLevel = 9;

// Pre-activate the middle segment
const initialClass = segmentsOrder[currentLevel];
const initialEffect = segmentsEffects[currentLevel];
document.querySelectorAll(`.thermo-segment.${initialClass}`).forEach(seg =>
seg.classList.add(initialEffect)
);

// FORWARD / LEFT / RIGHT
controlButtons.forEach(button => {
    button.addEventListener('click', () => {
        if (currentLevel >= segmentsOrder.length) return;
        const className = segmentsOrder[currentLevel];
        const effectClass = segmentsEffects[currentLevel];
        const segments = document.querySelectorAll(`.thermo-segment.${className}`);
        segments.forEach(seg => seg.classList.add(effectClass));
        currentLevel++;
    });
});

// RÜCKWÄRTS BUTTON
rückwärtsBtn.addEventListener("click", () => {
    if (currentLevel <= 0) return;
    currentLevel--;
    const className = segmentsOrder[currentLevel];
    const effectClass = segmentsEffects[currentLevel];
    const segments = document.querySelectorAll(`.thermo-segment.${className}`);
    segments.forEach(seg => seg.classList.remove(effectClass));
});

// STOP BUTTON - RESET EVERYTHING
stopBtn.addEventListener("click", () => {
    segmentsOrder.forEach((cls, i) => {
        document.querySelectorAll(`.thermo-segment.${cls}`).forEach(el =>
            el.classList.remove(segmentsEffects[i])
        );
    });
    currentLevel = 0;
});
