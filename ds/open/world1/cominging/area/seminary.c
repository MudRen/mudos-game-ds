/* �p�� */
inherit ROOM;
void create()
{
        set("short", "�p�p��");
        set("long",@LONG
�o�O�@�Ӥp�p���p�ѡA�b�o�оɪ��Ѯv�Ať���O�W�@�����ӷݪ���
�k��A�ӱХX�Ӫ��ǥͤj���j�W�����A���L�]���ܦh�O�����W���H�A�b
�Υ~���y�᭻�A���Ѫ�B�A������G�C
LONG
        );
        set("exits", ([
  "south" : __DIR__"sidestreet3.c",
]));
        set("objects", ([
  __DIR__"npc/teacher.c" : 1,
]));
        set("no_clean_up", 0);
        set("light", 1);
        set("no_exert",1);
        set("no_magic",1);
        set("no_cast",1);
        set("no_kill",1);
        set("no_fight",1);
        setup();
}

int valid_leave(object me, string dir)
{
        if( dir == "south" && me->query_temp("Confucius") )
                me->delete_temp("Confucius");
        return ::valid_leave(me, dir);
}
