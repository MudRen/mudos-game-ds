#include <weapon.h>
#include <ansi.h>

  inherit GUN;

  void create()
  {
          set_name("�Xù����j",({"suicide gun","gun"}));
          set("long","�o�O�@��p����������j�A�@����˶񤻵o�l�j�C\n");
          set_weight(4600);
          if( clonep() )
                  set_default_object(__FILE__);
          else {
                  set("unit", "��");
                  set("value",380);
                  set("rigidity",500);    //�s�W: �w��
                  set("material","iron");
          }
          set("wield_msg","$N�q�f�U�̮��X�@��$n, �ñN$n���O�I�˸m�Ѷ}�C\n");
          set("unwield_msg", "$N�N�⤤��$n�O�I�˸m����, �é�J�f�U���C\n");
          set("bullet_type","left_gun");     //�i�Τl�u����
          set("max_load",6);                 //�̤j�˶�q
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


  msg =  HIW " �i�ڤۤC��ֳ��j" HIW "�u�W�x�W�C���j�� �G���դj���|�G\n\n\n" NOR;
  msg +=HIY +"    "+ me->query("name")+"�|�_�Xù����j���ۤw�Ӷ��ޤ@�g....\n" NOR;
    msg += HIC "\n(�@�n�T�G���j�n�T�����d....)\n" NOR; 
          if(random(7) < i ) {
     msg += HIR "\n\n    "+  me->query("name")+"�@�n�\\�]���\\�a�˦b�a�W�A�ݨӬ������[�F...\n\n";
          message("world:world1:vision",msg     ,users() );
            me->die();      
          return 1;
          }
          msg += CYN "���G����Ƥ]�S�o��...\n\n" NOR;
  message("world:world1:vision",msg     ,users() );
          return 1;
  }

