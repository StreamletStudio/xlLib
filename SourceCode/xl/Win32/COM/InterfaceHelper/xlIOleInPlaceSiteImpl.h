//--------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlIOleInPlaceSiteImpl.h
//    Author:      Streamlet
//    Create Time: 2012-09-01
//    Description: 
//
//    Version history:
//
//
//--------------------------------------------------------------------

#ifndef __XLIOLEINPLACESITEIMPL_H_3B8F8EF3_1F26_4BB1_8C31_AF9827AE5BFE_INCLUDED__
#define __XLIOLEINPLACESITEIMPL_H_3B8F8EF3_1F26_4BB1_8C31_AF9827AE5BFE_INCLUDED__


#include <oleidl.h>
#include <xl/Win32/COM/xlComDef.h>
#include <xl/Win32/COM/InterfaceHelper/xlIOleWindowImpl.h>

namespace xl
{
    template <typename T = IOleInPlaceSite>
    class IOleInPlaceSiteImpl : public IOleWindowImpl<T>
    {
    public:
        XL_COM_INTERFACE_BEGIN()
            XL_COM_INTERFACE(IOleInPlaceSite)
            XL_COM_INTERFACE_CHAIN(IOleWindowImpl<T>)
        XL_COM_INTERFACE_END()

    public: // IOleInPlaceSite Methods
        STDMETHOD(CanInPlaceActivate)()
        {
            return E_NOTIMPL;
        }

        STDMETHOD(OnInPlaceActivate)()
        {
            return E_NOTIMPL;
        }

        STDMETHOD(OnUIActivate)()
        {
            return E_NOTIMPL;
        }

        STDMETHOD(GetWindowContext)(IOleInPlaceFrame **ppFrame,
                                    IOleInPlaceUIWindow **ppDoc,
                                    LPRECT lprcPosRect,
                                    LPRECT lprcClipRect,
                                    LPOLEINPLACEFRAMEINFO lpFrameInfo)
        {
            return E_NOTIMPL;
        }

        STDMETHOD(Scroll)(SIZE scrollExtant)
        {
            return E_NOTIMPL;
        }

        STDMETHOD(OnUIDeactivate)(BOOL fUndoable)
        {
            return E_NOTIMPL;
        }

        STDMETHOD(OnInPlaceDeactivate)()
        {
            return E_NOTIMPL;
        }

        STDMETHOD(DiscardUndoState)()
        {
            return E_NOTIMPL;
        }

        STDMETHOD(DeactivateAndUndo)()
        {
            return E_NOTIMPL;
        }

        STDMETHOD(OnPosRectChange)(LPCRECT lprcPosRect)
        {
            return E_NOTIMPL;
        }
    };

} // namespace xl

#endif // #ifndef __XLIOLEINPLACESITEIMPL_H_3B8F8EF3_1F26_4BB1_8C31_AF9827AE5BFE_INCLUDED__
