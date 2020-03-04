#include <ansi.h>
#include <path.h>
inherit ROOM;
void entercheck(object ob);
void create()
{
set("short",HIC"�ۥ����u�@��a"NOR);
set("long",
HIW"�o�̬O�ۥ��g�F�F���a��A�Q���M��C���O�L�{�b���}�F�A
�A�ݨ�@�Ӭ��k�C�L�N�O�ۥ����U�z�F�A�O���U�ۥ����C�n���
���ܡA�Цb�d���O�W�d�����ڧa�I�o���٦���L�q�D�A�q����L
�a��A�i�H�ۤv�ոաI^^\n"NOR);
set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/1" : 1,
__DIR__"npc/jobi" : 1,
]));
set("light", 1);
set("exits", ([ /* sizeof() == 4 */
"luky":"/u/l/luky/workroom.c",
"shengsan":"/u/s/shengsan/workroom.c",
"alickyuen":"/u/a/alickyuen/workroom.c",
"wiz" : "/d/wiz/hall1",
]));
set("no_fight", 1);
set("no_clean_up", 0);
set("valid_startroom", 1);
setup();
call_other("/obj/board/steps_b","???");
}
void init()
{
 call_out("leave_message",3,this_player());
 call_out("entercheck",2,this_player());
}
void entercheck(object ob)
{
if(userp(ob))
{
if(wiz_level(ob) < wiz_level("(immortal)"))
{
message_vision(HIR"���񻡡G"+ob->name()+" �A�i���n��ż�o�̡I\n"NOR, ob);
} else 
{
message_vision(HIM"\n�R�Z�g���D: �A�n�I "+ob->name()+"�I���a���y�[�d�ڡI\n"NOR, ob);
}
}
return;
}
void leave_message(object me)
{
object steps,ob1,ob2;
if(steps=find_player("steps"))
{
if(me->query("id")!="steps")
{
ob1=find_object(__DIR__"workroom");
ob2=present("steps",ob1);
if(ob2) return;
add("guest",me->query("id")+" - ");
tell_object(steps,"�����쫴���i�ӤF�I("+me->query("name")+")\n");
tell_object(me,"�����n�A�b�A�֨����\n");
} else //of if(me->query("id")!="steps")
{
if(query("guest"))
{
tell_object(me,"���ѨӹL���H��:"+query("guest")+"\n");
delete("guest");
} else //of if(query("guest"))
{
//tell_object(me,"�����٨S���H�ӹL\n");
}
}
} else //of if(steps=find_player("steps"))
{
add("guest",me->query("id")+" - "); 
tell_object(me,"�ۥ��{�b���b�a��,���ƪ��ܽЯd��.\n");
}
}

