data = { status: 'Critical' };

Vue.component('my-cmp', {
  data: function () {
    return {
      status: 'Critical'
    }
  },
  // below is an example of what not to do
  // data: function () {
  //   return data;
  // },
  methods: {
    changeStatus: function () {
      this.status = 'Normal';
    }
  },
  template: '<p>Server status: {{ status }} (<button @click="changeStatus">Change</button>)</p>'
});

new Vue({
  el: '#app'  
});
