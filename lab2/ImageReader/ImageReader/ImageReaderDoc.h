
// ImageReaderDoc.h : interface of the CImageReaderDoc class
//


#pragma once
#include <gdiplus.h>
#include <memory>


class CImageReaderDoc : public CDocument
{
protected: // create from serialization only
	CImageReaderDoc() noexcept;
	DECLARE_DYNCREATE(CImageReaderDoc)

// Attributes
public:
	void SetImage(const CString& imagePath);
	CString GetImage();

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CImageReaderDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

private:
	CString m_pImage;
};
