inherit ITEM;
#include <ansi.h>
void create()


{
        set_name(HIY"���y"NOR, ({"soccer", "soccer"}));
        set_weight(1000);
        set("unit", "��");
        set("long", @LONG�@�ӶW�j�O���y
LONG);
        set("value", 99999);

        setup();
}


void init() 
{          
 add_action("fire","kickout");
}
int fire(string str)
{



 object target,targetenv;
  object kickout;
  
  if(!str || str == "") return 0;
  target=present(str,environment(this_player()));
  if(!target) target = find_living(str);
  if(!target) {
  write(HIC+"�ӭ�,�к˷ǤF�A���I�I�I\n"+NOR);
  return 1;}
  targetenv=environment(target);
  
  if(target != this_player())
   write(HIB + "�A�ΤO�����y��h" + this_object()->query("name") + HIB + "��" +
        HIG + (string)target->query("name") + HIB + "�åX�C���C\n"+
        this_object()->query("name") + HIW + "�ֳt������" + HIB + 
        (string)target->query("name") + HIB + "����V���h�I�I�I\n"+NOR);
  else
  {
        write(HIW+"�A�����ۤv�C\n"+NOR);
        return 1;
  }
  tell_room(environment(this_player()),""+HIW+


       (string)this_player()->query("name")+HIC+
       "��@�Ө��y��b�a�W�A�ΤO���@�}��L�h�V"+HIW+
       (string)target->query("name")+HIC+"�A���_���b"+ HIW +
        (string)target->query("name")+HIC+"�������W�I\n"
       ,({this_player(),target}));
  tell_object(target, 
HIR+"\n�A�����e�@�¡M���ۤ���]�����D�F....\n\n"+NOR+
"�A���Ӯɵoı�ۤv�w�Q��X�C���A�̵}�O�o�����W���H��F�@�}�C\n"
);
        target->move("/u/p/promise/workroom");
  
  return 1;
}

