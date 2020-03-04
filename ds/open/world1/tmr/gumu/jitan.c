// Room: /d/gumu/jitan.c
// Last Modifyed by Winder on Jan. 14 2002

inherit ROOM;
#include <ansi.h>

void do_gain(object me, string name);

void create()
{
        set("short", HIC"�۫�"NOR);
        set("long",@long
�@���ſ������۫ǡA���e���ۤ@�Ӳ��¡A�W���e��ۤ@�ǥʪG�A
���䭻�봲�o�X�n���������A�@�ǥj�ӧ̤l���N�I�ǥj�Ӫ��q�f������
�e��(offer)�b���¡A�ⰼ�Ψӧi���������^�F�C
long);

        set("exits",([
                "west" : __DIR__"mudao21",
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
      add_action("do_jibai","offer");
//      add_action("do_ketou","ketou"); 
}

int do_jibai(string arg)
{
        object ob, me=this_player();
        
        ob = present("head", me);
        if ( arg == "head")
        {
                if ( ! ob )
                            return notify_fail("�A�S���H�Y�A�L�k�����C\n"); 
                  if(me->is_busy() ) return notify_fail("�A�����ۡA�S���Ű������C\n");

                if( ob->query("name") == "���ӥ�������"
                          || ob->query("name") == "�x��i������"
                          || ob->query("name") == "�����T������" ) {
                        message_vision(CYN "$N�����q�q�a�W�F�X���T�Y�A�N$n�e��b���¤W�C\n" NOR,me,ob);
                        do_gain(me, ob->query("name"));
                        destruct(ob);
                         return 1;
                }
                return notify_fail("�o���H�Y�n�H���O�j�Ӫ��q�f�A�|���|�O�A�����H�F�H\n");
        }
    return notify_fail("�A�Q�n�����򲽫��H\n");
}

void do_gain(object me, string name)
{
        string msg = HIR"\n�i�����H�ӡj";
        if(name=="���ӥ�������")
                msg += HIY"���u�в]��u���ӥ��v�ש��ݦb"+ me->name(1)+"���⤤�A�o�Ӹq�|�b����W�ǤF�}�ӡC\n\n" NOR;
        else 
                msg += HIY""+ me->name(1)+"���j�Ӭ������q�f���q�|�b����W�ǤF�}�ӡC\n\n" NOR;

        message("world:world1:vision",msg,users());
        tell_object(me, HIG"�A�o��@�I�n��F�C\n"NOR);
        me->add("popularity",1); //�n��
        me->start_busy(1);
}
