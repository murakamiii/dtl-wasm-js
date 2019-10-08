fetch('dtl.wasm').then(response => 
  response.arrayBuffer()
).then(bytes => 
  WebAssembly.instantiate(bytes)
).then(obj => {
  console.log(obj.instance.exports.my_func());
})

const modulePromise = new Promise(resolve =>
  mod.onRuntimeInitialized = _ => {
    resolve(mod);
  }
)

module.exports = modulePromise
module.exports.default = modulePromise