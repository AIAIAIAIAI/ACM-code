bool CLex::GenToken(vector<CToken> *pTokenList)

{

     bool bTag=true;                      

     m_iPos=0;                            

     m_pTokenList=pTokenList;  

    m_szSource=FileRead(m_szFileName.c_str());

     m_szSource.push_back(' ');

     m_iNonTerminal=0;                     

     m_szBuffer="";                     

     m_iRow=1;                           

     int TmpPos=0;

     m_pTokenList->clear();               

            while (m_iPos<m_szSource.length() && bTag)

     {      

        if (m_szSource[m_iPos]=='\n'&& TmpPos!=m_iPos)

        {

             m_iRow++;

             TmpPos=m_iPos;

        }

        m_szBuffer.push_back(m_szSource.at(m_iPos)); 

        bTag=Process(m_szLexTbl[m_iNonTerminal][m_szSource[m_iPos]<128?m_szSource[m_iPos]:128]);

        if (!bTag)

        {

             EmitError(m_szFileName+"("+itos(m_iRow)+"):´Ê·¨·ÖÎö´íÎó£¬Çë¼ì²éµ¥´Ê");

             return false;

        }

      m_iPos++;                       

     }

     return bTag;

}