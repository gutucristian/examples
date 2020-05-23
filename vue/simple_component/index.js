// data = { status: 'Critical' };

/*
// Example below regisers component GLOBALLY
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
*/

// Example below regisers component LOCALLY
var cmp = {
  data: function () {
    return {
      status: 'Critical'
    }
  },
  methods: {
    changeStatus: function () {
      this.status = 'Normal';
    }
  },
  template: '<p>Server status: {{ status }} (<button @click="changeStatus">Change</button>)</p>'
};

new Vue({
  el: '#app',
  components: {
    'my-cmp': cmp // register component declared above LOCALLY to this instance ONLY 
  }
});

new Vue({
  el: '#app2'  
});