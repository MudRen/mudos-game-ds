// Room: /open/world1/manto/sky2_1f/map_5_13.c

inherit ROOM;
string look_book(object me);

void create()
{
	set("short", "�Ѧa�|�i���]");
	set("long", @LONG
�b��������W��ۤ@�����y(book)�A�W���g�ۡG�u�Ѧa���k�v�A���T
�Q½�\(read)���C

LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"map_3_13",
]));
	set("no_clean_up", 0);
        set("objects",([
    __DIR__"npc/goldman1" :1,
    __DIR__"npc/goldman2" :1,
    __DIR__"npc/goldman3" :1,
    __DIR__"obj/red_axe" :1,
    __DIR__"obj/green_sword" :1,
]));
        set("item_desc",([
        "book":(: look_book :),
        ]));

	setup();
}
void init()
{
 add_action("do_read","read");
}

int do_read(string arg)
{
        if(arg=="book")
        {
                this_player()->start_more(@SKY_RULES
        
                           �i�Ѧa�|���W�j
�@�B  �Y��T�����

      ���������Ҿ֦����Ҧ�����(�N�O�����o)�A���i�H�[�J��L����
      �o�ˬO�קK�U�����������L�װ����C
      �P�ɤ]�U�줣�n�N�ۤv������ɵ��L�H�ϥΡC�ӭn�⨤��e���L
      �H�ɡA����POST�b���|�� Terra Board���G�A�Ѫ��ѥH�W�P�N��
      �N��Kickout��~�i�e���L�H�C
      �p�e���P������,�i�HPOST�bTerra Board�A�Ѫ��ѦP�N�C
      �t�~�T����N�������|�A�p�ۤv�������|�A���n�Ʊ楻�|���s��
      �A�A�Ӧ����n�����ɡA����POST�b Terra Board�g���ѷ|ĳ�q�L
      ��\�A�l�i���}���|�C
      �H�ϤW�z�W�w�̡A�N�v�X�ڡA�÷|�����D�M�w�O�_�[�H�q�r���C

�G�B  �Y�T�D��PK��L���a

      ���������T��PK��L���a�A���ѥ����o�X����O���ҥ~�C
      �өҦ�PK�������������a�A���ߧY�q���b�u�����ѤH���A�ñN��
      �pPOST�bTerra Board�A���e���������]�APKER ID�M�QPK��ID�A
      �Ӧb�u������,�����O�̤j��U�C

      �ӥ����N�C�X�q�r�¦W��A���������ҥi�����C�Y�QPK�ɡA�u�W
      �L���ѥH�W�i�����@�ҡA�h�гQPK�������ۦ�POST�L�{�A�ƫ�g
      ���ѩΥH�W�H���d�ҡA��N���C�J�q�r�¦W��C

      ���D��PK�H�~�A���������P�L�H����L�ȯɡA����POST�b
      Terra Board�Ѫ��ѥH�W�M�w��ʡA���i�ۦ�PK���C
      �H�ϤW�z�W�w�̡A�N�v�X���ڡA�å����D�����p�M�w�O�_�[�H�q
      �r�C

SKY_RULES
);
        return 1;
        }
        notify_fail("�A�Q�n�\\Ū����?\n");
        return 0;
}

string look_book(object me)
{
        return @SKY_BOOK
        
�A�ݨ�o���Ѫ��ʭ��W�g�ۡi�Ѧa���k�j�|�Ӥj�r�A�p�G�A�Q�F�ѳo��
�Ѫ����e�γ\�A�i�H�յ۾\Ū�ݬ�(read book)�C

SKY_BOOK;
}
