#include <weapon.h>
#include <ansi.h>

  inherit GUN;

  void create()
  {
          set_name("俄羅斯手槍",({"suicide gun","gun"}));
          set("long","這是一把小型的左輪手槍，一次能裝填六發子槍。\n");
          set_weight(4600);
          if( clonep() )
                  set_default_object(__FILE__);
          else {
                  set("unit", "把");
                  set("value",380);
                  set("rigidity",500);    //新增: 硬度
                  set("material","iron");
          }
          set("wield_msg","$N從口袋裡拿出一把$n, 並將$n的保險裝置解開。\n");
          set("unwield_msg", "$N將手中的$n保險裝置關閉, 並放入口袋中。\n");
          set("bullet_type","left_gun");     //可用子彈種類
          set("max_load",6);                 //最大裝填量
          init_gun(10); 
          setup();
  }

  void init()
  {
          add_action("do_shoot","shoot");
  }

  int do_shoot()
  {
          object me;
          int i;
          string id,msg;
          me=this_player();
          id=me->query("id");
          switch(id) {
          case "eji": i=6;break;
          case "hcc": i=5;break;
          case "judith":i=4;break;
          case "exri": i=3;break;
            case "windwalk": i=2;break;
            default:  i=7;break;
          }       


  msg =  HIW " 【夢幻七域快報】" HIW "線上掌上遊戲大賽 二次博大機會：\n\n\n" NOR;
  msg +=HIY +"    "+ me->query("name")+"舉起俄羅斯手槍往自已太陽穴一射....\n" NOR;
    msg += HIC "\n(一聲響亮的槍聲響徹雲宵....)\n" NOR; 
          if(random(7) < i ) {
     msg += HIR "\n\n    "+  me->query("name")+"一聲吭\也不吭\地倒在地上，看來活不長久了...\n\n";
          message("world:world1:vision",msg     ,users() );
            me->die();      
          return 1;
          }
          msg += CYN "結果什麼事也沒發生...\n\n" NOR;
  message("world:world1:vision",msg     ,users() );
          return 1;
  }

