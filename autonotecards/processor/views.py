from django.contrib.auth.models import User
from django.http import HttpResponse
from django.shortcuts import render, get_object_or_404
from .models import PdfPack
from django.core.files.storage import FileSystemStorage
from django import forms
from .forms import NewPdfForm



def home(request):
    pack = PdfPack.objects.all()
    return render(request, 'home.html', {'PdfPacks': pack})


def new_pdf(request, pk):
    pack = get_object_or_404(PdfPack, pk=pk)
    # get a gemeroc user for now:
    user = User.objects.first()
    if request.method == 'POST':
        form = NewPdfForm(request.POST)
        if form.is_valid():
            pdfFile = form.save(commit=False)
        


    return render(request, 'new_pdf.html')
