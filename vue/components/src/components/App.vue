<template>
  <div>
    <app-servers></app-servers>
  </div>
</template>

<script>
  import Home from './Home.vue'

  export default {
    components: {
      'app-servers': Home // register Home component locally and bind it to 'app-servers' custom selector
    }
  }
</script>

<style>

</style>
