inherit BANK;

void create()
{
        set("short", "���H����");
        set("long", @LONG
�o�O���a�̤j�������A���ݩ�u�Ʊ��s���v�����~�A�O��í�a������
�A�������H���E�����O�H�s�b���A�A�i�H�ݬݥ�������W����СA�H�F��
�o�a�������ѤF����A�ȡC
LONG
        );
	set("objects",([	
		__DIR__"npc/guard" : 2,
		__DIR__"npc/banker" : 1,
	])	);
        set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"street4",
        ]));
  	set("no_kill",1); //�O����s��.
	 set("item_desc", ([
        "���" : @LONG
   ���H�������Ѫ��A�Ȧ�:

deposit      : �s��
withdraw     : ����	

LONG
        ]) );

	set("light",1);
        set("no_clean_up", 0);

        setup();

}

