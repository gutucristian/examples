new Vue({
  el: '#app',
  data: {
    name: 'Cristian',
    age: 21,
    image: 'https://i.insider.com/592d7378b74af41b008b4fd2?width=1136&format=jpeg'
  },
  methods: {
    getRandNum: function() {
      return Math.random();
    },
    changeName: function(event) {
      this.name = event.target.value;
    }
  }
});