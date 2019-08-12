const mod = require('./wasm/dtl')

const modulePromise = new Promise(resolve =>
  mod.onRuntimeInitialized = _ => {
    resolve(mod);
  }
)

module.exports = modulePromise
module.exports.default = modulePromise