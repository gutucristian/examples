new Vue({
  el: '#app',
  data: {
    counter: 0,
    secondCounter: 0
  },
  computed: {
    // only runs when "counter" from data changes
    // this increases render time by reducing unnecesarry
    // compute 
    output: function() {
      console.log("call output");
      return this.counter > 3 ? 'Greater than 3' : 'Smaller than 3';
    }
  },
  methods: {
    // is also executed when we increase "counter" because vue
    // does not know whether or not function implementation depends
    // on "counter" from app data
    secondOutput: function() {
      console.log("call secondOutput");
      return this.secondCounter > 3 ? 'Greater than 3' : 'Smaller than 3';
    }
  }
});