inherit ROOM;

void create()
{
        set("short", "�}�f");
        set("long", @LONG
�A����@�Ӥs�}�e���A���k���䳣�躡�F�ֵ��q��A��m�״I�A���e
�`�ʡA�}�e���@�p�����o�O�b�ө��A�W���ۨ�Ӳ`�`���O�r�A�u�j�ӡv
�A�@����h�A�̭��ɬO�@�����·t�A�@���L��ɪ��·t�A�p�G�A���ө��]
�ƪ��ܡA�]�\�i�H�ݪ�����M���C
�̭��٦��@�q���C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2",
  "east" : "/open/world1/cominging/purple_sun/psin3",
]));
        set("objects", ([ /* sizeof() == 1 */
          __DIR__"prey" : 1,
]));
        set("outdoors","land");
        set("light",1);
 set("no_clean_up", 0);

        setup();

}

