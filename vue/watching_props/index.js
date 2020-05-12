new Vue({
  el: '#app',
  data: {
    balance: 0,
    message: ''
  },
  computed: {
    output: function() {
      if (this.balance < 0) {
        return `Danger! Negative balance: $${this.balance}`;
      } else if (this.balance < 25) {
        return `Warning! Low balance: $${this.balance}`;
      } else {
        return `Balance: $${this.balance}`;
      }
    }
  },
  watch: {
    balance: function(value) {
      if (this.balance < 0) {
        this.message = `Danger! Negative balance: $${this.balance}`;
      } else if (this.balance < 25) {
        this.message = `Warning! Low balance: $${this.balance}`;
      } else {
        this.message = `Balance: $${this.balance}`;
      }
    }
  }
});