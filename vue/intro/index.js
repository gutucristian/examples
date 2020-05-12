var app = new Vue({
	el: '#app',
	data: {
		title: 'Foo',
		link: 'https://gutucristian.github.io/',
		builtInLink: '<a href="https://gutucristian.github.io/">My Blog</a>',
		x: undefined,
		y: undefined,
		count: 0
	},
	methods: {
		changeTitle: function(event) {
			this.title = event.target.value;
		},
		broadcastTitle: function() {
			alert(this.title);
		},
		updateCoordinates: function(event) {
			this.x = event.clientX,
			this.y = event.clientY
		},
		increment: function (step, event) {
			this.count += step;
			console.log(JSON.stringify(event, null, 2));
		},
		alertMe: function(event) {
			alert(event.target.value);
		}
	}
});