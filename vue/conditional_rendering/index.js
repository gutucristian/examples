new Vue({
  el: '#app',
  data: {
    show: false,
    message: 'show'
  },
  methods: {
    update: function() {      
      this.message = this.message === 'show' ? 'hide' : 'show';      
      this.show = !this.show;
    }
  }
});