Drupal.locale = { 'pluralFormula': function ($n) { return Number((($n==1)?(0):(($n==0)?(1):(($n==2)?(2):(((($n%100)>=3)&&(($n%100)<=10))?(3):(((($n%100)>=11)&&(($n%100)<=99))?(4):5)))))); }, 'strings': {"":{"Not published":"\u0644\u0645 \u064a\u0646\u0634\u0631","Edit":"\u062a\u062d\u0631\u064a\u0631","Configure":"\u0636\u0628\u0637","Not restricted":"\u063a\u064a\u0631 \u0645\u0642\u064a\u062f","Flag translations as outdated":"\u0639\u0644\u0651\u0645 \u0627\u0644\u062a\u0631\u062c\u0645\u0627\u062a \u0642\u062f\u064a\u0645\u0629"}} };