inherit __DIR__"lightroom";
void create()
{
set("short","���w��");
set("long",@LONG
�A�w�g�i�J�F����������A�o�̦��۫ܦh���i��ĳ����
�u�y«�A���A���ǸC���}�����A���ɫo�S�Q���X�M�A���H�P��
�D�`�L�k�F�ѳo�̡A�o�̬O�������窺�T�u�}�A�|�P���ۤ@��
������l���F��C
LONG
    );
set("item_desc", ([
    "�ѷ���" : (: look_mirror :),
    "mirror" : (: look_mirror :),
]));
set("exits",([
"northeast" : __DIR__"folight_1",
]));
set("light_room",__DIR__"folight_3");
set("light_number",2);
set("light_area","one");
setroom();
setup();
}          

