#include <ansi.h>
inherit NPC;
void create()
{
set_name("��L��",({"vicch"}));
set("level",25);
set("age",45);
set("long","�@�ӱ��H���w�����j�]�Y�A�q�L�����i�ݨ��@�����C\n");
set("gender", "�k��");
        setup();
}
void init()
{
         add_action("do_force","force");
}
int do_force(string arg)
{
        string dest, cmd;
        object ob,me;
        me=this_player();
        ob=this_object();
//      if( this_player()->query("id")!="acme")return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("���O�榡�Rforce <�Y����> to <���O>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("�o�̨S�� " + dest + "�C\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"�����ۡA�S����ť�A���X�ϡC\n");
        command(cmd);
        return 1;
}
