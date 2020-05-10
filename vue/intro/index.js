var app = new Vue({
	el: '#app',
	data: {
		title: 'Foo',
		link: 'https://gutucristian.github.io/',
		builtInLink: '<a href="https://gutucristian.github.io/">My Blog</a>'
	},
	methods: {
		changeTitle: function(event) {
			this.title = event.target.value;
		},
		broadcastTitle: function() {
			alert(this.title);
		}		
	}
});