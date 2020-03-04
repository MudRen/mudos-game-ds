inherit ROOM;

void create()
{
        set("short","�}���p�q");
        set("long",@LONG
�A�����b�@���}���p�q�̡A�A���U�F�@�U�|�P�A�o�{�q�̫e�ᥪ
�k���ݦӤ��}�A��y�p�q�t�ٵ��A�@�إ��~�ԩM���P��A�ϩ��ЫU��
�@�����g���B���������|�b���o�͡C
LONG
        );
        set("world","past");
        set("exits",([/*sizeof()==3*/
                "southeast":__DIR__"hill4.c",
        ]));
//      set("outdoors","forest");
        set("no_clean_up",0);

set("item_desc",([ 
"�s�_":"��n�O�@�ӤH�i�H�L�h(climb)���_�ءA��n���b�ⶳ���p�U�C\n",
"��Y�߸g�g��":@LONG
�[�ۦb���ġA��`��Y�iù�K�h�ɡA�Ө���ĭ�ҪšA
��@���W�̡C�٧Q�l�A�⤣���šA�Ť�����A��Y�O�šA
�ŧY�O��A���Q���ѡA��_�p�O�C�٧Q�l�A�O�Ѫk�ŬۡA
���ͤ����A�������b�A���W����A�O�G�Ť��L��A�L���Q
���ѡA�L���ջ�ި��N�A�L���n����Ĳ�k�A�L���ɡA�D��
�L�N�ѬɡA�L�L���A��L�L���ɡA�D�ܵL�Ѧ��A��L�Ѧ�
�ɡA�L�W�����D�A�L����L�o�A�H�L�ұo�G�A�д���ئ�A
�̯�Y�iù�K�h�G�A�ߵL��ê�A�L��ê�G�A�L�����ơA��
���A�˹ڷQ�A�s���I�n�A�T�@�Ѧ�A�̯�Y�iù�K�h�G�A
�o�ȿ��hù�T�ƤT�д��A�G����Y�iù�h�A�O�j���G�A�O
�j���G�A�O�L�W�G�A�O�L�����G�A�ణ�@���W�A�u�ꤣ��
�C�G����Y�iù�K�h�G�A�Y���G��G���ʹ��͡A�iù����
�A�iù�����͡A�д��ıC�F�C
LONG 
]));
        set("objects", ([
                __DIR__"npc/bonze_adv_master.c" : 1,
                ]));

        setup();
}
void init()
{
}
int do_climb(string arg)
{ 
    object me=this_player();
    if(!arg || arg !="�s�_") return notify_fail("�A�n��(climb)����?\n"); 
    {
    message_vision(""+me->name(1)+"��}�åΪ��A�C�C�����i�s�_�̡E�E\n",me); 
    tell_room(environment(me),me->query("name")+"���F�L�ӡC\n",me );
    me->start_busy(5);
    call_out("CLIMB_ON",5,me);
    }
    return 1;
}
void CLIMB_ON()
{ 
     object me=this_player();
     message_vision(""+me->name(1)+"�p���l�l�����W�s���E�E��F�I��F�s���F�C\n",me);  
     {
     me->move("/open/world1/jangshow/fox_area/taroom");
     me->start_busy(2);  
     }
     return;
}
