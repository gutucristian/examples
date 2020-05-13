new Vue({
  el: '#app',
  data: {
    attachRed: false,
    color: 'green',
    width: 50,
    height: 50
  },
  computed: {
    divClasses: function() {
      return {
        red: this.attachRed,
        blue: !this.attachRed
      }
    },
    myStyle: function() {
      return {
        width: this.width + 'px',
        height: this.height + 'px'
      }
    }
  }
});