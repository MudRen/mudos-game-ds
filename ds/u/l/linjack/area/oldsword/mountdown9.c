#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�D��");
 set("long",@LONG
�A�g�L�F�n�X�Ѫ����{�ש��F�o�F. �q�L�F�@�j���N�u
��F�z�n����@�I�I���ݾ���, ���Tı�o���ǯ�D....���_��
�h�N���s�ϥh�F.
LONG
    );
 set("exits",([ "north":__DIR__"mountdown8",
                "southeast":__DIR__"field",]));
 set("no_clean_up", 0);
 setup();
}
int valid_leave(object me, string dir)
{
 if( dir=="southeast")
  write(YEL"\n�A�}�l��������h....���^�ݾ���.\n\n"NOR);
 return ::valid_leave(me, dir);
}
