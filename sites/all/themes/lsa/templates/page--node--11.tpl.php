<style>
span.submitted {
    display: none;
}
</style>

<div class="container">
 <div class="col-sm-offset-3 col-md-6">
   <div class="intromain">
     <img src="<?php global $base_url; echo $base_url; ?>/sites/all/themes/lsa/images/logo-smart.png" alt="logo">
     <h2>Welcome to <b>Lebanon smart</b> application</h2>
     <hr>
     <div class="content">
  <?php print render($page["content"]); ?>
  </div>
  </div>
 </div>
</div>
<footer>
  <div class="container">
    <ul>
     <li><a href="#">About</a></li>
     <li><a href="#">Terms & Conditions</a></li>
     <li><a href="#">Privacy Policy</a></li>
     <li><a href="#">How to use</a></li>
     <li><a href="#">Contact</a></li>
    </ul>
    <p>© Copyright 2017 - Lebanon smart</p>
  </div>
</footer>