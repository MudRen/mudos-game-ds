//���ө�bbad�ؿ��U...�����@��..���ȷh�Ӧ�..leei �d
//�Ѹt�~�ǩӽƻs�Ө�..
#include <ansi.h>
#include <armor.h>
 
inherit WRISTS;
 
void create()
{
          set_name("�G�A���ݤ���", ({ "t1000 wrists", "wrists" }) );
          set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", @LONG
�o�O�@�ӥѲG�A���ݩһs���������A
�i�H���H�ܦ���L���F��C
        pra <name>
LONG
        );
                set("value", 10000000);
                set("material", "linen");
                set("armor_prop/hit", 200);
                set("armor_prop/shield", 200);
                set("armor_prop/armor", 200);
                set("armor_prop/dodge", 200);
                set("armor_prop/show_damage",1);
                set("armor_prop/bar",5);
                set("armor_prop/sou",5);
                set("armor_prop/wit",5);
        }
        setup();
}

 
void init()
{
      add_action("do_face","pra");
}


int do_face(string str)
{
         object me,target;
         string msg;
         me = this_player();

         if(!str) {
                   if(!me->query("cface"))
                             return notify_fail("���O�榡: pra <���ܧΪ����~>\n");
                   else {
                             msg = (string)me->query("name");
                             me->set("title",me->query("ctitle"));
                             me->set("nickname",me->query("cnickname"));
                             me->set("name",me->query("cname"));
                             me->set("id",me->query("cid"));
                             me->delete("ctitle");
                             me->delete("cnickname");
                             me->delete("cname");
                             me->delete("cid");
                             me->delete("cface");

                             return 1;
                   }
         }

         if (!target = present(str,environment(me)))
                   return notify_fail("�S�o�ӤH��..�C\n");
         if(!me->query("cface")) {
                   me->set("ctitle",me->query("title"));
                   me->set("cnickname",me->query("nickname"));
                   me->set("cname",me->query("name"));
                   me->set("cid",me->query("id"));
                   me->set("cface", "change");
         }
         me->set("title",target->query("title"));
         me->set("nickname",target->query("nickname"));
         me->set("name",target->query("name"));
         me->set("id",target->query("id"));
         return 1;
}
int query_autoload() { return 1; }
