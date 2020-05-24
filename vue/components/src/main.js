import Vue from 'vue'
import App from './components/App.vue'

Vue.config.productionTip = false
// Vue.component('app-servers', Home) // init custom selector for Home component

new Vue({
  render: h => h(App)
}).$mount('#app')
