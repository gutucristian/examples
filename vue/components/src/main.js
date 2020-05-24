import Vue from 'vue'
import App from './App.vue'
import Home from './components/Home.vue'

Vue.config.productionTip = false
Vue.component('app-server-status', Home) // init custom selector for Home component

new Vue({
  render: h => h(App),
}).$mount('#app')
