inherit ITEM;

void create()
{
          set_name("�K���p�[���K�Z",({"bagi book","book","quest-bagi-book"}) );
        set_weight(100);
        set("long",@long
�o�O�@���ѥ֤w�x�����p�U�l�A�W�Y�g�ۡu�K���p�[���v�C
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value",1);
                set("volume",1);
                set("material","paper");
        }
        setup(); 
}
