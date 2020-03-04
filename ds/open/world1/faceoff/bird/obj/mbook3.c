#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�Ĩ�", ({ "medicine book","book" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "�@���M�Ѥ����Ǫ̾ǲ�(learn)���Ĩ�C");
		set("no_give", 1);
        }
        setup();
}

void init()
{
       add_action("do_read","learn");
}

int do_read(string arg)
{
        object me, obj, tar_ob;
        string tar;
        me = this_player();
        obj = this_object();

        if( !arg || sscanf(arg, "from %s", tar)!=1 )
                return notify_fail("�Х� learn from <���~> �ӾǲߡI\n");
        if( !objectp(tar_ob=present(tar, me)) )
                return notify_fail("�A���W�S���o�ӪF��I\n");
        if( tar_ob != this_object() )
                return notify_fail("�A����q�o�W���Ǩ����F��I\n");
        if( me->query_skill("literate") == 60 )
                return notify_fail(CYN"�A�w�g�i�H�x���o���Ѫ����e�F�C\n"NOR);
	if( me->query_skill("literate") < 39 )
                return notify_fail(CYN"�o���Ѫ����e��A�Ө��٤����F�C\n"NOR);
        if( me->is_fighting() )
                return notify_fail(CYN"�b�԰���Ū��?!..\n"NOR);
        if( sizeof(me->query_temp("is_busy")) )
                 return notify_fail(CYN"�A�{�b���b���A�L�kŪ�ѣ�..�C\n"NOR);
        if( me->query_skill("literate") == 0 )
                return notify_fail(CYN"�A�٬O�媼�C...-_-..�C\n"NOR);
        if( me->query_temp("read_book") == 1 )
                return notify_fail(CYN"�A�w�g�bŪ�ѤF ...-_-\n"NOR);
        if( me->query("ap") < 11 )
                return notify_fail(CYN"�A����O�����P�I\n"NOR);

        message_vision("$N�ݤF�ݤ⤤�Ĩ�...\n"  ,me);
        obj->set_temp("read_book",1);
        obj->set("no_drop", 1);
        obj->set("no_give", 1);
        obj->set("no_sac", 1);
        call_out("read_book", 1, me, obj, 1);

        return 1;
}

void read_book(object me, object obj, int flag)
{
        if( !me || environment(obj) != me )
        {
                obj->delete("no_drop");
                obj->delete("no_sac");
        }

        if( flag > 1 && me->query("mp") < 21 )
        {
                message_vision(HIR"$N�����@���V�áA�n�ɯ��F�_�ӡC\n"NOR, me);
                me->delete_temp("read_book");
        }

        if( flag == 1 )
        {
                message_vision(HIW"$N�P�P��a�A�N�a���UŪ�_�Ĩ�C\n"NOR, me);
                me->receive_damage("mp",10); 
                me->start_busy(2);
                call_out("read_book", 3, me, obj, 2);
        }
        else if( flag && flag < 5 && flag > 1 )
        {
                message_vision(HIW"$N���E��|����Ū���Ĩ�C\n"NOR, me);
                me->receive_damage("mp",10); 
                me->improve_skill("literate",10);
                me->start_busy(2);
                call_out("read_book", 3, me, obj, ++flag);
        }
        else if( flag == 5 )
        {
                message_vision(HIW"$N�X�_�Ĩ�A�q�Q��~Ū�쪺�s���C\n"NOR, me);
                me->receive_damage("mp",20); 
                me->improve_skill("literate",20);
                me->start_busy(2);
                me->delete_temp("read_book");
        }
        else tell_object(me, this_object()->name() + "�G���~�I�гq�� Faceoff book �ǻ����~�I\n");
}

