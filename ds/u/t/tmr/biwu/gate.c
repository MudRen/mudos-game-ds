// �s��(adx) by snow 2000-05-15

inherit ROOM;

void create ()
{
        set ("short", "��Z���j��");
        set ("long", @LONG
�o�̬O��Z�j�|�|�����j���A�@�y���������P�{�A�W�ѡy��Z
���z�T���^���j�r�C�o�̸g�`�|��U����������Z�j�|�C�Ҧ����H��
�����|�ѥ[�A���F�O�ɿ������A�A�]�i�H�o�{�L���ȫȤ��ɩ��o���
�A���G�K���D�D���ժ��Pı�C
LONG);
        set("no_fight",1);
        set("no_clean_up",1);
        set("exits", ([
                "north"   : __DIR__"zoulang",
                "east": "/open/world1/tmr/area/city-door",
        ]));
        set("objects", ([
                __DIR__"npc/gongping" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        object ob, where;

        if (!where=find_object(__DIR__"gate"))
                where=load_object(__DIR__"gate");
          if(!objectp(ob=present("da go ko", where)) ) return ::valid_leave(me,dir);

        if ( !wizardp(me) && dir=="north" ) {
                  if( ob->query("fangshi")!="single" )
                        return notify_fail("�{�b�S�������Z�A�A����i�h�C\n");
        }
        return ::valid_leave(me, dir);
}

