#include <room.h>
inherit ROOM;
void create()
{
 set("short","��^�j�Y�_�I");
 set("long",@LONG
�A����F�o�Ӱj�Y���_�I, ��M��ı�o���I�N, ���L
�|�B�٬O���Ǫ��, �]���ǽ���, �����ݨ�e���q�A���e
���L, ���T�ϧA�~�F�@�|��, ��Ӱj�Y�Q�˳]���}�}�G�G.
LONG
    );
 set("exits",([
               "west":__DIR__"hall4",
               "south":__DIR__"inroom1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
