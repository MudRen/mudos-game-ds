#include <ansi.h>
inherit NPC;
void create()
{
        set("title", WHT"���J������"NOR );
        set_name( HIG"����"NOR , ({ "coco" }) );
        set("level",1);
        set("race","�H��");
        set("gender","�k��");
        set("age",17);
        set("nickname", RED"�ɩ�¾�u���j�H"NOR);
        set("long","�������Ӫ��Ǫ��C\n");
        setup();
        carry_object("/u/f/fanny/wp/ssword.c")->wield();
add_money("coin", 99999);
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
        if( this_player()->query("id")!="fanny")return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("���O�榡�Rforce <�Y����> to <���O>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("�o�̨S�� " + dest + "�C\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"�����ۡA�S����ť�A���X�ϡC\n");
        command(cmd);
        return 1;
}
