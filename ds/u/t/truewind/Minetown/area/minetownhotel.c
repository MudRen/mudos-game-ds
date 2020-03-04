inherit ROOM;

void create()
{
	set("short", "�q�l�b�פ�");
	set("long", @LONG
�o�O�q�l�b�ת������A�Ů�Q���M�s�A�P�~�Y���F���Ѫ����Τ�
�P�A�b�׸��Y���Ӥp�ù��A������ۻ��P�����ָ`�ءA�����n���A��
�ֶV�ӶV�H���A�A�i�H�����U�ӡA�A�n�n�ɨ��o�̩Ҵ��Ѫ��A�ȡA�O
�ҵξA(sleep)�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"minetown1",
]));

	setup();
}
void init()
{
        object me,out;
        me = this_player();
        out = find_object(__DIR__"minetown1");
        if(out) out->set("full",1);
        me->add_busy(1);
        call_out("sleep",0,me);
        call_out("wakeup",6,me);
        call_out("leaveroom",7,me);
        call_out("empty",7,out);
        return;
}

void sleep(object me)
{
        if(!me) return;
        me->remove_all_enemy();
        message("system","\n�ն����j��֦b���伽���...ZzzZzz \n\n",me);
        me->disable_player_cmds("�A�Ϊ����ΪA�A�@�ڤ���]�ʤ��F...�C\n");
        //this_object()->disable_player(" <�����H��>");
        me->set_temp("block_msg/all", 2);
        return;
}

void wakeup(object me)
{
        if(!me) return;
        me->set("hp",me->query("max_hp"));
        me->set("mp",me->query("max_mp"));
        me->set("ap",me->query("max_ap"));
        me->wakeup(2);
        me->start_busy(2);
        me->delete_temp("mine/tent");
        return;
}

void leaveroom(object me)
{
        if(!me) return;
        tell_room(this_object(),"�A����A���_�ӡA�M�ᨫ�X�b�סC\n");
        me->move(__DIR__"minetown1");
        tell_room(environment(me),me->name()+"�q�b�׸̨��F�X�ӡC\n",({me}));
        return;
}

void empty(object room)
{
        room->delete("full");
        return;
}
