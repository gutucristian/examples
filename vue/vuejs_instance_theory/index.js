var data = {
  title: 'The VueJS Instance',
  showParagraph: false,
  counter: 0
}

var vm1 = new Vue({
  // el: '#app1',
  data: data,  
  methods: {
    show: function() {      
      this.showParagraph = !this.showParagraph;      
      this.updateTitle(`The VueJS Instance (${this.counter})`);
      this.counter++;
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
    // title: function(value) {
    //   alert(`Title changed, new value: "${value}"`);
    // }
  }
});



vm1.$mount('#app1');

vm1.newProp =  'Foobar!';

console.log(vm1);
console.log(vm1.$data);

/*
  proof that data in Vue instance is the data that we passed
  in to the Vue constructor via the options object
*/
console.log(vm1.$data === data);

console.log(vm1.$refs);
console.log(vm1.$refs.myButton);

/*
  We can still manipulate an element by accessing it directly
  in the DOM using Vue's ref, but any changes made might
  be overwritten. In the example below we change the content of
  the heading. Since the heading content is tied to the title variable
  via interpolation what we set below will be overwritten when
  title is updated.
*/

vm1.$refs.heading.childNodes[0].data = "Lalala";

// this is wrong because it replaces the TextNode that Vue knows about with a new one -- essentially killing our binding
// vm1.$refs.heading.innerText = "Lalala";

setTimeout(function() {
  /*
    Notice how Vue proxies the instance's data and methods
    so we can directly access them by name instead of through
    the container objects themselves (e.g., Vue instance data,
    methods).
  */
  vm1.title = 'Changed by timer!';  
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

var vm3 = new Vue({
  template: '<h1>Hello!</h1>'
});

// vm3.$mount('#app3');

// this will build our DOM based on the vm3 template
vm3.$mount();
// append vm3's compiled template (stored in the $el prop) to the app3 container
document.getElementById('app3').appendChild(vm3.$el);