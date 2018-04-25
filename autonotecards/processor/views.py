from django.contrib.auth.models import User
from django.http import HttpResponse
from django.shortcuts import render, get_object_or_404
from .models import PdfPack
from django.core.files.storage import FileSystemStorage
import logging



def home(request):
    pack = PdfPack.objects.all()
    return render(request, 'home.html', {'PdfPacks': pack})


def new_pdf(request, pk):
    pack = get_object_or_404(PdfPack, pk=pk)
    if request.method == 'POST':
        desc = request.POST['desc']
        divisions = request.POST['divs']
        pdfFile = request.FILES['pdfFile']
        user = User.objects.first()
        fileSys = FileSystemStorage()
        fileName = fileSys.save(pdfFile.name, pdfFile)
        return render(request, 'new_pdf.html', {'uploadedFileUrl': fileSys.url(fileName)})
        

    return render(request, 'new_pdf.html')
