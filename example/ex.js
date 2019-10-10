const mod = require('../dist/dtl')

const modulePromise = new Promise(resolve =>
  mod.onRuntimeInitialized = _ => {
    resolve(mod);
  }
)

const drawMap = (vector) => {
  for (let i = 0; i < vector.size(); i++) {
    let row = ''
    for (let j = 0; j < vector.get(i).size(); j++) {
      row += vector.get(i).get(j).toString()
    }
    console.log(row)
  }
}

const init = async () => {
  const mod = await modulePromise
  const rougueMap = mod.getSimpleRogueLike(48, 36, 7, 1, 4, 1, 5, 2, 5, 2)
  drawMap(rougueMap)
}

init()