// app.js — replicates cgpacal.cpp logic in the browser and provides validation

(function(){
  const form = document.getElementById('cgpa-form');
  const resultSection = document.getElementById('result');
  const resultText = document.getElementById('result-text');
  const resetBtn = document.getElementById('reset');

  function parseInput(id){
    const el = document.getElementById(id);
    const val = parseFloat(el.value);
    if (Number.isFinite(val)) return val;
    return null;
  }

  function formatNumber(n){
    return Math.round(n*100)/100; // show two decimal places roughly
  }

  form.addEventListener('submit', function(e){
    e.preventDefault();
    const c1 = parseInput('cgpa1');
    const c2 = parseInput('cgpa2');
    const c3 = parseInput('cgpa3');
    const c4 = parseInput('cgpa4');

    const inputs = [c1,c2,c3,c4];
    const missing = inputs.some(x=>x===null);
    if (missing){
      resultSection.classList.remove('hidden');
      resultText.innerHTML = '<strong>Error:</strong> Please enter valid numbers for all levels.';
      return;
    }

    // Basic range validation — allow up to 10.0 since some schools use 10 scale
    for (let i=0;i<inputs.length;i++){
      if (inputs[i] < 0 || inputs[i] > 10){
        resultSection.classList.remove('hidden');
        resultText.innerHTML = `<strong>Error:</strong> Level ${100*(i+1)} value is out of expected range (0-10).`;
        return;
      }
    }

    // replicate C++ formula: (cgpa1 + cgpa2 + cgpa3*2 + cgpa4*2) / 6
    const cgpa = (c1 + c2 + c3 * 2 + c4 * 2) / 6;

    resultSection.classList.remove('hidden');
    resultText.innerHTML = `Your CGPA is: <strong>${formatNumber(cgpa).toFixed(2)}</strong>`;
  });

  resetBtn.addEventListener('click', function(){
    form.reset();
    resultSection.classList.add('hidden');
    resultText.textContent = '';
  });
})();