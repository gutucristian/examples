new Vue({
  el: '#app',
  data: {
    name: 'Cristian'
  },
  methods: {
    updateName: function(event) {      
      this.name = event.target.value
    }
  }
});