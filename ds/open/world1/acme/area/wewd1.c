//������  Edit By -Acme-

#include <ansi2.h>

#define Y_SIZE 10       //���y��
#define X_SIZE 30       //��y��
                        //�j�p��o�̴N��F...
                        //���y�� ���W ��y�� �j��Y�@�ƭȱN�|��BUG

#define FISH   10       //�ƶq�üơA�V�j�X�{���v�V�C

inherit ROOM;
string being(int i);
mixed *area=allocate(Y_SIZE);
int fishing(object me,object obj,int yy,int xx);

void create()
{
        set("short", "����");
        set("long", @LONG
�o�O�p�ˮǪ��p���A����i�ݨ��@�y����A����U���p�˲M�������A
�٥i�@���ˤ����p����ۦb����ۡA�ˮǦ��\�h�����Ȧb�������A���G��
��i�[�A���Ȥ��ѦۥD���L���ۡC
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"pons",
		"east" : __DIR__"pass8",
	]));
	set("objects",([
		__DIR__"npc/shipman" : 3,
	]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
