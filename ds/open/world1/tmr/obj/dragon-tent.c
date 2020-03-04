#include <ansi.h>
inherit ITEM;

void do_heal(object me);

void create()
{
    set_name("�s�ֱb�O", ({"dragon-skin tent", "tent", "_TENT_"}));
    set_weight(500);
    set("long2", @LONG
�o�O�@�ӫܤ[�ܤ[�H�e���G�ƤF�A����ӦW�s�㥧���������P�ǧJ�S��
���~���H�A�@�_��@�ӹA�����x�u�@�A��H�]�����ѡC�����H���@�ɥߨ�
�ѱۦa��A�o�X�G�@�L�i�B�C�L�̳��ܽT�w�ۤv�n��í�w���J�B���B�ͤl�A
�o�S����t�@�صL�k���y���P���C�����L�̨짧�R���_�I�s���ϮɡA�㥧
���P�ǧJ�]���o�i�X���R���ˡA�Ʀܧ�˱K�����Y�C�ӧA�A�ثe�N���B�b�L
�̴��g�b�s�W�ϥιL���b�O���C

        �C�ӤH�߸̳����@���_�I�s�A�u�O�A�S���W�h�L�C
    ������A�ש����R�������ɡA�w�g���L�F�A�o�O�����ڱ��M���C

�ϥΤ�k: use tent
LONG
               );
        set("long", query("long2"));
    if( clonep())
        set_default_object(__FILE__);
    else
    {
        set("short","�s�ֱb�O��");
        set("value", 10000);
    }
    set("no_recall",1);
    set("no_clean_up",1);
    set("no_goto", 1);
//    set_max_encumbrance(1);
    setup();

}

void init()
{
    add_action("do_sleep","use");
}

void sleep(int index, object me)
{
    object *obs;
    int i;

    if(!me)
                destruct(this_object());
    if(me->is_ghost() || !environment(me))  {
        obs = all_inventory(this_object());
        for(i=0;i<sizeof(obs);i++)
            obs[i]->move(environment(this_object()));
        delete("useing");
        delete("no_get");
        delete("no_sac");
        set("used",1);
        call_out("dest_obj",1);
        return;
    }

    if(environment(me) != this_object())
    {
        me->delete_temp("sleeping");
        call_out("dest_obj",1);
        return;
    }

    switch(index)
    {
    case 0 :
                tell_room(environment(this_object()),HIM+ name(1) + "�̶ǨӰ}�}���I�n�C\n"NOR,me);
        write(HIR"\n[�Aı�o���֨I���A���W�N�εۤF]\n\n"NOR);
        do_heal(me);
        break;

    case 1 :
                write(HIR"\n .......... ��Z�Cz��\n\n"NOR);
        do_heal(me);
        break;

    case 2 :
                write(HIG"\n���ӫ�Aı�o�믫�n�F�ܦh�A���F�Ө���A�q" + name(1)+ "�̨��F�X�ӡC\n\n"NOR);
        tell_room(environment(this_object()),HIW+me->name(1)+"�q"+ name(1)+"�̨��F�X�ӡC\n"NOR,me);
        set("long","�]�ϥιL���ܱo�}�l������"+ name(1)+"�C");
        set_name("�}�l���b�O",({"broken tent","tent"}));

        delete("useing");
        delete("no_get");
        delete("no_sac");

        set("used", 1);
        me->start_busy(0);
        me->delete_temp("sleeping");
        all_inventory(this_object())->move(environment(this_object()));
        break;
    }

    index++;
    if(index < 3) {
                if(!me->is_busy() )
                        me->add_busy(3);
                 call_out("sleep", 6,index,me);
        }
    else call_out("dest_obj", 2);
}

void do_heal(object me)
{
        me->receive_heal("hp", 1500);
        me->receive_heal("mp", 1500);
        me->receive_heal("ap", 1500);
}

void dest_obj()
{
    message_vision(HBK"\t�@�}���j�ӡA�N$N�j���F�C\n"NOR,this_object());
    destruct(this_object());
}

int do_sleep(string str)
{
    object ob = this_object(), me = this_player();
    if(!str || str != "tent") return 0;

    if(me->is_busy() || me->is_fighting())
        return notify_fail("�A���b���A�S�ŧ@��L�Ʊ��C\n");
    if( !environment(me)->query("outdoors"))
        return notify_fail("�A�u��b��~�ϥΡC\n"); // by -alickyuen@ds-
    if( query("used"))
        return notify_fail("�o�ӱb�O�w�g���b�ϥΤF�C\n");
    if(me->is_ghost())
                return notify_fail("�A�{�b�O����L�k�ϥ��s�ֱb�O�C\n");
    if(me->query_temp("killer"))
        return notify_fail("�A���F�H�Ȯɤ��i�H�ϥ��s�ֱb�O�C\n");
    if(me->query_temp("invader"))
        return notify_fail("�A�����F���a�ȮɵL�k�ϥ��s�ֱb�O�C!\n");
    if(me->query("hp") < 0)     
                return notify_fail("�A�w�g�ͩR���M�F�A�S�k�l�f�b�O�C\n");

    set_max_encumbrance(999999);
    if(environment(ob) == me)
    {
        message_vision( HIG"$N�q��������X�@��$n�A�ܧ֪���$n�f�n�F�C\n"NOR,me,ob);
        ob->move( environment(me) );
        ob->set("no_drop", 1);
    }
    message_vision(HIW"\n$N�@�ӸG���A��$n�p�F�i�h�A��F�Ӧn��m�A�εΪA�A�����F�U�ӡC\n\n"NOR,me,ob);
        set("long", query("long2") +  "�o��" +ob->name(1)+ "���Q�ϥΤ��C\n" );

    set("used",1);
    set("no_get", 1);
    set("no_sac", 1);

    me->move(ob);
    me->set_temp("sleeping",1);
    me->start_busy(16);
    call_out("sleep",5 , 0, me);
    return 1;
}
