var vm1 = new Vue({
  el: '#app1',
  data: {
    title: 'The VueJS Instance',
    showParagraph: false
  },
  methods: {
    show: function() {
      this.showParagraph = true;
      this.updateTitle('The VueJS Instance (Updated)');
    },
    updateTitle: function(title) {
      this.title = title;
    }
  },
  computed: {
    lowercaseTitle: function() {
      return this.title.toLowerCase();
    }
  },
  watch: {
    title: function(value) {
      alert(`Title changed, new value: "${value}"`);
    }
  }
});

vm1.newProp =  "Foobar!";

console.log(vm1);

setTimeout(function() {
  /*
    Notice how Vue proxies the instance's data and methods
    so we can directly access them by name instead of through
    the container objects themselves (e.g., Vue instance data,
    methods).
  */
  vm1.title = 'Changed by timer!'
  vm1.show();
}, 3000);

var vm2 = new Vue({
  el: '#app2',
  data: {
    title: 'The second instance'
  },
  methods: {
    onChange: function() {
      // Vue proxies the instance's data here so we don't have to do vm1.data.title
      vm1.title = 'Changed!';
    }
  }
});