#include <ansi.h>
inherit NPC;
void create()
{
 set_name(HIW"�K�Ѩ�"NOR, ({"seraphim"}) );
set("long",
                HIW"�K�Ѩ�"NOR"�A�O�����Ϫ̤��̰���̡A���L���ֱq�ƥ�\n"
                "��ҰʡA�ߤ@���ϩR(�Τ�����)�N�O�q�|���C"HIW"�K\n"
                "�Ѩ�"NOR"�L�εL��B�P���������q�A�O�º骺���M���\n"
                "���F��A�H�䮶�ʳгy�ͩR�C�Y�O�����{����H�e\n"
                "�ɡA�O�H���l�|�������X�{�C�j�H��C�ԶîɥN��\n"
                "�j�����H�ɨȴ��y�z�b�����s�y�e����"HIW"�K�Ѩ�"NOR"���g\n"
                "�L�A�]�ӯd�U�F���l�Φ����l�����A���ǻ��C\n"
        );
        set("level",100);
        set("evil",-999);
        set("age",random(100)*random(100));
 set("attitude", "heroism");
set_spell("god-fire",150);
set_spell("god-benison",150);
set_spell("recite-sutra",100);
set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
        (:command,"cast god-fire":),
(:command,"cast god-benison":),
(:command,"cast recite-sutra":),
        }) );
        set("chat_chance",80);
        set("chat_msg",({
  (: command("cast god-fire") :),
}));
        setup();
carry_object("/u/s/sonicct/test/Angel/longinuslance.c")->wield();
carry_object("/u/s/sonicct/test/Angel/angelcloth.c")->wear();
carry_object("/u/s/sonicct/test/Angel/angelskirt.c")->wear();
carry_object("/u/s/sonicct/test/Angel/angelboots.c")->wear();
}
void init()
{
add_action("do_order","order");
}
int do_order(string arg)
{
string dest, cmd;
object ob,me;
me=this_player();
ob=this_object();
        if( this_player()->query("id")!="sonicct")return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("���O�榡�Rorder <�Y�Ѩ�> to <���O>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("�o�̨S�� " + dest + "�C\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"�����ۡA�S����ť�A���X�ϡC\n");
        command(cmd);
        return 1;
}
